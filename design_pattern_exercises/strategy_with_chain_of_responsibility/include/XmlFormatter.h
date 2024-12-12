#pragma once
#include "Formatter.h"

namespace XmlFormatter
{
    class XmlFormatter : public Formatter::Formatter
    {
        public:
            [[nodiscard]] virtual std::string format() const override; 
    };
}