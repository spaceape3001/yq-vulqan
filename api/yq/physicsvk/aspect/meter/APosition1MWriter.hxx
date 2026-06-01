////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition1D.hpp>
#include <yq/tachyon/command/position/AddPosition1DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition1DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition1DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void APosition¹D::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition¹D>();
        w.property(UNSAFE, "position", &APosition¹D::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹D::on_set_position1);
        w.slot(UNSAFE, &APosition¹D::on_set_positionX);

        w.slot(UNSAFE, &APosition¹D::on_add_position1);
        w.slot(UNSAFE, &APosition¹D::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹D::on_multiply_position);
        w.slot(UNSAFE, &APosition¹D::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹D::on_multiply_positionX);
    }
}
