#pragma once
#include <memory>
#include <vector>
#include "Observer.h"

namespace Subject
{
    class Subject 
    {
        public:
            void addObserver(const std::shared_ptr<Observer::Observer>& observerToAdd);
            void removeObserver(const std::shared_ptr<Observer::Observer>& observerToRemove);
        protected:
            void notifyAllObservers() const;
        private:
            std::vector<std::shared_ptr<Observer::Observer>> observers;

            [[nodiscard]] bool ifNotAlreadyObservingThisSubject(const std::shared_ptr<Observer::Observer>& observer) const;
    };
}