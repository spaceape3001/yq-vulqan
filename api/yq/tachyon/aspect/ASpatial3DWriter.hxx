////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ASpatial3D.hpp"
#include "AOrientation3DWriter.hxx"
#include "APosition3DWriter.hxx"
#include "AScale3DWriter.hxx"

#include <yq/tachyon/command/position/MoveBy3DCommand.hpp>
#include <yq/tachyon/command/position/MoveByXDCommand.hpp>
#include <yq/tachyon/command/position/MoveByYDCommand.hpp>
#include <yq/tachyon/command/position/MoveByZDCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void ASpatial³D::init_meta(TachyonMeta::Writer<C>&w)
    {
        APosition³D::init_meta(w);
        AOrientation³D::init_meta(w);
        AScale³D::init_meta(w);

        w.slot(UNSAFE, &ASpatial³D::on_move³);
        w.slot(UNSAFE, &ASpatial³D::on_moveˣ);
        w.slot(UNSAFE, &ASpatial³D::on_moveʸ);
        w.slot(UNSAFE, &ASpatial³D::on_moveᶻ);
    }
}
