////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <memory>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Font;
    class FontAtlas;
    class FontFamily;
    class TrueTypeFont;
    
    using FontPtr           = Ref<Font>;
    using FontCPtr          = Ref<const Font>;

    using FontFamilyPtr     = Ref<FontFamily>;
    using FontFamilyCPtr    = Ref<const FontFamily>;
    
    using FontFamilySpec    = std::variant<std::monostate, std::string, FontFamilyCPtr>;
}
