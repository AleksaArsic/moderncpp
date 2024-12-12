#pragma once

namespace Observer
{
    class Observer
    {
        public:
            virtual ~Observer() = default;
            virtual int getId() const noexcept = 0;
            virtual void update() = 0;

            friend bool operator==(const Observer& lhs, const Observer& rhs);
    };
}