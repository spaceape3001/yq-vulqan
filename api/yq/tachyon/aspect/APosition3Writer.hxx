////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/command/position/AddPosition3DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition3DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition3DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition³D>();
        w.property(UNSAFE, "position", &APosition³::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition³::on_set_position3);
        w.slot(UNSAFE, &APosition³::on_set_positionX);
        w.slot(UNSAFE, &APosition³::on_set_positionY);
        w.slot(UNSAFE, &APosition³::on_set_positionZ);

        w.slot(UNSAFE, &APosition³::on_add_position3);
        w.slot(UNSAFE, &APosition³::on_add_positionX);
        w.slot(UNSAFE, &APosition³::on_add_positionY);
        w.slot(UNSAFE, &APosition³::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition³::on_multiply_position);
        w.slot(UNSAFE, &APosition³::on_multiply_position3);
        w.slot(UNSAFE, &APosition³::on_multiply_positionX);
        w.slot(UNSAFE, &APosition³::on_multiply_positionY);
        w.slot(UNSAFE, &APosition³::on_multiply_positionZ);
    }
}
