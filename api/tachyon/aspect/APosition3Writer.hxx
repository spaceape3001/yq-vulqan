////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition3.hpp>
#include <tachyon/command/position/AddPosition3Command.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/AddPositionZCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition3Command.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <tachyon/command/position/SetPosition3Command.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/command/position/SetPositionZCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition³::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition³>();
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
