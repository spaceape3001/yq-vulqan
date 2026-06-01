////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition2D.hpp>
#include <yq/tachyon/command/position/AddPosition2DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition2DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition2DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition²D::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition²D>();
        w.property(UNSAFE, "position", &APosition²D::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition²D::on_set_position2);
        w.slot(UNSAFE, &APosition²D::on_set_positionX);
        w.slot(UNSAFE, &APosition²D::on_set_positionY);

        w.slot(UNSAFE, &APosition²D::on_add_position2);
        w.slot(UNSAFE, &APosition²D::on_add_positionX);
        w.slot(UNSAFE, &APosition²D::on_add_positionY);
        
        w.slot(UNSAFE, &APosition²D::on_multiply_position);
        w.slot(UNSAFE, &APosition²D::on_multiply_position2);
        w.slot(UNSAFE, &APosition²D::on_multiply_positionX);
        w.slot(UNSAFE, &APosition²D::on_multiply_positionY);
    }
}
