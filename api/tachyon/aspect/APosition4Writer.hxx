////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition4.hpp>
#include <tachyon/command/position/AddPosition4Command.hpp>
#include <tachyon/command/position/AddPositionWCommand.hpp>
#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/command/position/AddPositionZCommand.hpp>
#include <tachyon/command/position/MultiplyPositionCommand.hpp>
#include <tachyon/command/position/MultiplyPosition4Command.hpp>
#include <tachyon/command/position/MultiplyPositionWCommand.hpp>
#include <tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <tachyon/command/position/SetPosition4Command.hpp>
#include <tachyon/command/position/SetPositionWCommand.hpp>
#include <tachyon/command/position/SetPositionXCommand.hpp>
#include <tachyon/command/position/SetPositionYCommand.hpp>
#include <tachyon/command/position/SetPositionZCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition⁴::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IPosition⁴>();
        w.property(UNSAFE, "position", &APosition⁴::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition⁴::on_set_position4);
        w.slot(UNSAFE, &APosition⁴::on_set_positionW);
        w.slot(UNSAFE, &APosition⁴::on_set_positionX);
        w.slot(UNSAFE, &APosition⁴::on_set_positionY);
        w.slot(UNSAFE, &APosition⁴::on_set_positionZ);

        w.slot(UNSAFE, &APosition⁴::on_add_position4);
        w.slot(UNSAFE, &APosition⁴::on_add_positionW);
        w.slot(UNSAFE, &APosition⁴::on_add_positionX);
        w.slot(UNSAFE, &APosition⁴::on_add_positionY);
        w.slot(UNSAFE, &APosition⁴::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition⁴::on_multiply_position);
        w.slot(UNSAFE, &APosition⁴::on_multiply_position4);
        w.slot(UNSAFE, &APosition⁴::on_multiply_positionW);
        w.slot(UNSAFE, &APosition⁴::on_multiply_positionX);
        w.slot(UNSAFE, &APosition⁴::on_multiply_positionY);
        w.slot(UNSAFE, &APosition⁴::on_multiply_positionZ);
    }
}
