////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ASpatial3.hpp"
#include "AOrientation3Writer.hxx"
#include "APosition3DWriter.hxx"
#include "AScale3DWriter.hxx"

#include <yq/tachyon/command/position/MoveBy3DCommand.hpp>
#include <yq/tachyon/command/position/MoveByXDCommand.hpp>
#include <yq/tachyon/command/position/MoveByYDCommand.hpp>
#include <yq/tachyon/command/position/MoveByZDCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASpatial³::init_meta(TachyonMeta::Writer<C>&w)
    {
        APosition³D::init_meta(w);
        AOrientation³::init_meta(w);
        AScale³D::init_meta(w);

        w.slot(UNSAFE, &ASpatial³::on_move³);
        w.slot(UNSAFE, &ASpatial³::on_moveˣ);
        w.slot(UNSAFE, &ASpatial³::on_moveʸ);
        w.slot(UNSAFE, &ASpatial³::on_moveᶻ);
    }
}
