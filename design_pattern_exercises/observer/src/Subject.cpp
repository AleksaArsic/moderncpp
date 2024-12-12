#include "Subject.h"
#include <algorithm>

namespace Subject
{
    void Subject::addObserver(const std::shared_ptr<Observer::Observer>& observerToAdd)
    {
        if(ifNotAlreadyObservingThisSubject(observerToAdd))
        {
            observers.push_back(observerToAdd);
        }
    }

    void Subject::removeObserver(const std::shared_ptr<Observer::Observer>& observerToRemove)
    {
        std::erase_if(observers, [observerToRemove]
                                 (auto existingObserver) 
                                 { return *existingObserver == *observerToRemove; });
    }

    void Subject::notifyAllObservers() const
    {
        for(const auto& observerToNotify : observers)
        {
            observerToNotify->update();
        }
    }

    [[nodiscard]] bool Subject::ifNotAlreadyObservingThisSubject(const std::shared_ptr<Observer::Observer>& observer) const
    {
        const auto itOfTheObserver = std::find(std::begin(observers), std::end(observers), observer);

        if (std::end(observers) == itOfTheObserver)
        {
            return true;
        }

        return false;
    }

}