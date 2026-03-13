////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScale4D.hpp>
#include <yq/tachyon/command/scale/AddScale4DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale4DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale4DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale⁴D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScale⁴D>();
        w.property(UNSAFE, "scale", &AScale⁴D::m_scale).tag(kTag_Save);
        
        w.slot(UNSAFE, &AScale⁴D::on_set_scale4);
        w.slot(UNSAFE, &AScale⁴D::on_set_scaleW);
        w.slot(UNSAFE, &AScale⁴D::on_set_scaleX);
        w.slot(UNSAFE, &AScale⁴D::on_set_scaleY);
        w.slot(UNSAFE, &AScale⁴D::on_set_scaleZ);

        w.slot(UNSAFE, &AScale⁴D::on_add_scale4);
        w.slot(UNSAFE, &AScale⁴D::on_add_scaleW);
        w.slot(UNSAFE, &AScale⁴D::on_add_scaleX);
        w.slot(UNSAFE, &AScale⁴D::on_add_scaleY);
        w.slot(UNSAFE, &AScale⁴D::on_add_scaleZ);
        
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scale);
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scale4);
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scaleW);
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scaleY);
        w.slot(UNSAFE, &AScale⁴D::on_multiply_scaleZ);
    }
}
