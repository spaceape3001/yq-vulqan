////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/APosition4.hpp>
#include <ya/commands/position/AddPosition4.hpp>
#include <ya/commands/position/AddPositionW.hpp>
#include <ya/commands/position/AddPositionX.hpp>
#include <ya/commands/position/AddPositionY.hpp>
#include <ya/commands/position/AddPositionZ.hpp>
#include <ya/commands/position/MultiplyPosition.hpp>
#include <ya/commands/position/MultiplyPosition4.hpp>
#include <ya/commands/position/MultiplyPositionW.hpp>
#include <ya/commands/position/MultiplyPositionX.hpp>
#include <ya/commands/position/MultiplyPositionY.hpp>
#include <ya/commands/position/MultiplyPositionZ.hpp>
#include <ya/commands/position/SetPosition4.hpp>
#include <ya/commands/position/SetPositionW.hpp>
#include <ya/commands/position/SetPositionX.hpp>
#include <ya/commands/position/SetPositionY.hpp>
#include <ya/commands/position/SetPositionZ.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

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
