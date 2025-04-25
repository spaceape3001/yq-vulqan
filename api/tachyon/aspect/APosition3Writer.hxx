////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/APosition3.hpp>
#include <tachyon/command/position/AddPosition3.hpp>
#include <tachyon/command/position/AddPositionX.hpp>
#include <tachyon/command/position/AddPositionY.hpp>
#include <tachyon/command/position/AddPositionZ.hpp>
#include <tachyon/command/position/MultiplyPosition.hpp>
#include <tachyon/command/position/MultiplyPosition3.hpp>
#include <tachyon/command/position/MultiplyPositionX.hpp>
#include <tachyon/command/position/MultiplyPositionY.hpp>
#include <tachyon/command/position/MultiplyPositionZ.hpp>
#include <tachyon/command/position/SetPosition3.hpp>
#include <tachyon/command/position/SetPositionX.hpp>
#include <tachyon/command/position/SetPositionY.hpp>
#include <tachyon/command/position/SetPositionZ.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <yt/tags.hpp>

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
