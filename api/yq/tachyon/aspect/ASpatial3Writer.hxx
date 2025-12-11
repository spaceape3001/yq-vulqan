////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ASpatial3.hpp"
#include "AOrientation3Writer.hxx"
#include "APosition3Writer.hxx"
#include "AScale3Writer.hxx"

#include <yq/tachyon/command/position/MoveBy3Command.hpp>
#include <yq/tachyon/command/position/MoveByXCommand.hpp>
#include <yq/tachyon/command/position/MoveByYCommand.hpp>
#include <yq/tachyon/command/position/MoveByZCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASpatial³::init_meta(TachyonMeta::Writer<C>&w)
    {
        APosition³::init_meta(w);
        AOrientation³::init_meta(w);
        AScale³::init_meta(w);

        w.slot(UNSAFE, &ASpatial³::on_move³);
        w.slot(UNSAFE, &ASpatial³::on_moveˣ);
        w.slot(UNSAFE, &ASpatial³::on_moveʸ);
        w.slot(UNSAFE, &ASpatial³::on_moveᶻ);
    }
}
