////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition4.hpp>
#include <yq/tachyon/command/position/AddPosition4Command.hpp>
#include <yq/tachyon/command/position/AddPositionWCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <yq/tachyon/command/position/SetPosition4Command.hpp>
#include <yq/tachyon/command/position/SetPositionWCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition⁴::init_meta(TachyonMeta::Writer<C>& w)
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
