////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class UIConsoleModel : public RefCount {
    public:
        struct Line {
            RGBA4F              color;
            std::string_view    text;
        };
        
        virtual ~UIConsoleModel(){}
        virtual size_t  line_count() const = 0;
        virtual Line    line(size_t) const = 0;
    };
}
