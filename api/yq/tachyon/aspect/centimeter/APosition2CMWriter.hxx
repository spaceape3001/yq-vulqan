////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/centimeter/APosition2CM.hpp>
#include <yq/tachyon/command/position/centimeter/AddPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition2CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²CM::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition²CM>();
        w.property(UNSAFE, "position", &APosition²CM::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition²CM::on_set_position2);
        w.slot(UNSAFE, &APosition²CM::on_set_positionX);
        w.slot(UNSAFE, &APosition²CM::on_set_positionY);

        w.slot(UNSAFE, &APosition²CM::on_add_position2);
        w.slot(UNSAFE, &APosition²CM::on_add_positionX);
        w.slot(UNSAFE, &APosition²CM::on_add_positionY);
        
        w.slot(UNSAFE, &APosition²CM::on_multiply_position);
        w.slot(UNSAFE, &APosition²CM::on_multiply_position2);
        w.slot(UNSAFE, &APosition²CM::on_multiply_positionX);
        w.slot(UNSAFE, &APosition²CM::on_multiply_positionY);
    }
}
