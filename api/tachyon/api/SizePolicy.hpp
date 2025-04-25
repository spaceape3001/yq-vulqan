////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq {
    template <typename> struct Vector1;
    template <typename> struct Vector2;
    template <typename> struct Vector3;
    template <typename> struct Vector4;
}

namespace yq::tachyon {
    enum class Sizing : uint8_t {
        Shrink,     //!< Thing can shrink
        Diminish,   //!< Shrink to contents
        Grow,       //!< Thing can grow
        Expand,     //!< Thing should get as big as it can
        Ignore      //!< Max space possible (preferrence)
    };
    
    using SizePolicy    = Flags<Sizing, uint8_t>;

    static constexpr SizePolicy kSizePolicy_Fixed   = {};
    static constexpr SizePolicy kSizePolicy_Minimum = SizePolicy(Sizing::Grow);
    static constexpr SizePolicy kSizePolicy_Maximum = SizePolicy(Sizing::Shrink);
    
    using SizePolicy¹   = Vector1<SizePolicy>;
    using SizePolicy²   = Vector2<SizePolicy>;
    using SizePolicy³   = Vector3<SizePolicy>;
    using SizePolicy⁴   = Vector4<SizePolicy>;
}

