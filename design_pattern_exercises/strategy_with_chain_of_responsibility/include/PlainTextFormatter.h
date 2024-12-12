#pragma once
#include "Formatter.h"

namespace PlainTextFormatter
{
    class PlainTextFormatter : public Formatter::Formatter
    {
        public:
            [[nodiscard]] virtual std::string format() const override; 
    };
}