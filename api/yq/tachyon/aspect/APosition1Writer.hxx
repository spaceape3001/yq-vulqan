////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition1.hpp>
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
    void APosition¹::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IPosition¹D>();
        w.property(UNSAFE, "position", &APosition¹::m_position).tag(kTag_Save);

        w.slot(UNSAFE, &APosition¹::on_set_position1);
        w.slot(UNSAFE, &APosition¹::on_set_positionX);

        w.slot(UNSAFE, &APosition¹::on_add_position1);
        w.slot(UNSAFE, &APosition¹::on_add_positionX);
        
        w.slot(UNSAFE, &APosition¹::on_multiply_position);
        w.slot(UNSAFE, &APosition¹::on_multiply_position1);
        w.slot(UNSAFE, &APosition¹::on_multiply_positionX);
    }
}
