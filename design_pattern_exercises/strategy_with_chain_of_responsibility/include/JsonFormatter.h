#pragma once
#include "Formatter.h"

namespace JsonFormatter
{
    class JsonFormatter : public Formatter::Formatter
    {
        public:
            [[nodiscard]] virtual std::string format() const override; 

        private:
            static constexpr const char* const END_OF_PROPERTY { "\",\n" };
    };
}