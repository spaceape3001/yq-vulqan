////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/centimeter/APosition3CM.hpp>
#include <yq/tachyon/command/position/centimeter/AddPosition3CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition3CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³CM::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition³CM>();
        w.property(UNSAFE, "position", &APosition³CM::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition³CM::on_set_position3);
        w.slot(UNSAFE, &APosition³CM::on_set_positionX);
        w.slot(UNSAFE, &APosition³CM::on_set_positionY);
        w.slot(UNSAFE, &APosition³CM::on_set_positionZ);

        w.slot(UNSAFE, &APosition³CM::on_add_position3);
        w.slot(UNSAFE, &APosition³CM::on_add_positionX);
        w.slot(UNSAFE, &APosition³CM::on_add_positionY);
        w.slot(UNSAFE, &APosition³CM::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition³CM::on_multiply_position);
        w.slot(UNSAFE, &APosition³CM::on_multiply_position3);
        w.slot(UNSAFE, &APosition³CM::on_multiply_positionX);
        w.slot(UNSAFE, &APosition³CM::on_multiply_positionY);
        w.slot(UNSAFE, &APosition³CM::on_multiply_positionZ);
    }
}
