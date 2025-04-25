////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition4.hpp>
#include <tachyon/command/position/AddPosition4.hpp>
#include <tachyon/command/position/AddPositionW.hpp>
#include <tachyon/command/position/AddPositionX.hpp>
#include <tachyon/command/position/AddPositionY.hpp>
#include <tachyon/command/position/AddPositionZ.hpp>
#include <tachyon/command/position/MultiplyPosition.hpp>
#include <tachyon/command/position/MultiplyPosition4.hpp>
#include <tachyon/command/position/MultiplyPositionW.hpp>
#include <tachyon/command/position/MultiplyPositionX.hpp>
#include <tachyon/command/position/MultiplyPositionY.hpp>
#include <tachyon/command/position/MultiplyPositionZ.hpp>
#include <tachyon/command/position/SetPosition4.hpp>
#include <tachyon/command/position/SetPositionW.hpp>
#include <tachyon/command/position/SetPositionX.hpp>
#include <tachyon/command/position/SetPositionY.hpp>
#include <tachyon/command/position/SetPositionZ.hpp>
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
