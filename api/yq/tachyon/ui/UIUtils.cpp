////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIUtils.hpp"
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    Vector2F    pivot_for(Cardinal v)
    {
        switch(v){
        case Cardinal::Unknown:
        case Cardinal::Center:
            return { 0., 0. };
        case Cardinal::NW:
            return { 0., 0. };
        case Cardinal::NNW:
            return { 0., 0. };
        case Cardinal::North:
            return { 0.5, 0. };
        case Cardinal::NNE:
            return { 1.0, 0. };
        case Cardinal::NE:
            return { 1.0, 0. };
        case Cardinal::ENE:
            return { 1.0, 0. };
        case Cardinal::East:
            return { 1.0, 0.5 };
        case Cardinal::ESE:
            return { 1.0, 1.0 };
        case Cardinal::SE:
            return { 1.0, 1.0 };
        case Cardinal::SSE:
            return { 1.0, 1.0 };
        case Cardinal::South:
            return { 0.5, 1.0 };
        case Cardinal::SSW:
            return { 0.0, 1.0 };
        case Cardinal::SW:
            return { 0.0, 1.0 };
        case Cardinal::WSW:
            return { 0.0, 1.0 };
        case Cardinal::West:
            return { 0.0, 0.5 };
        case Cardinal::WNW:
            return { 0.0, 0.0 };
        default:
            return ZERO;
        }
    }
}
