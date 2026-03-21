////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/function/FNScreenMapper2M.hpp>
#include <yq/tachyon/function/FNScreenMapper3M.hpp>
#include <yq/tachyon/function/FNScreenUnmapper2M.hpp>
#include <yq/tachyon/function/FNScreenUnmapper3M.hpp>

namespace yq::tachyon {
    struct ScreenScaleSnap {
        //! 2D screen/physics mapping
        FNScreenMapper²M            screen2map;

        //! 2D screen/physics reverse mapping
        FNScreenUnmapper²M          screen2rev;

        //! 3D screen/physics mapping
        FNScreenMapper³M            screen3map;

        //! 3D screen/physics reverse mapping
        FNScreenUnmapper³M          screen3rev;
    };
}
