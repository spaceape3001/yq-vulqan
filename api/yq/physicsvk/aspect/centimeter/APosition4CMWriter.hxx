////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/physicsvk/aspect/centimeter/APosition4CM.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPosition4CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionWCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPosition4CMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionWCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/physicsvk/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition⁴CM::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition⁴CM>();
        w.property(UNSAFE, "position", &APosition⁴CM::m_position).tag(kTag_Save);
        
        w.slot(UNSAFE, &APosition⁴CM::on_set_position4);
        w.slot(UNSAFE, &APosition⁴CM::on_set_positionW);
        w.slot(UNSAFE, &APosition⁴CM::on_set_positionX);
        w.slot(UNSAFE, &APosition⁴CM::on_set_positionY);
        w.slot(UNSAFE, &APosition⁴CM::on_set_positionZ);

        w.slot(UNSAFE, &APosition⁴CM::on_add_position4);
        w.slot(UNSAFE, &APosition⁴CM::on_add_positionW);
        w.slot(UNSAFE, &APosition⁴CM::on_add_positionX);
        w.slot(UNSAFE, &APosition⁴CM::on_add_positionY);
        w.slot(UNSAFE, &APosition⁴CM::on_add_positionZ);
        
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_position);
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_position4);
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_positionW);
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_positionX);
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_positionY);
        w.slot(UNSAFE, &APosition⁴CM::on_multiply_positionZ);
    }
}
