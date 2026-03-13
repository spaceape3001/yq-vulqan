////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScale3D.hpp>
#include <yq/tachyon/command/scale/AddScale3DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale³D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScale³D>();
        w.property(UNSAFE, "scale", &AScale³D::m_scale).tag(kTag_Save);
        
        w.slot(UNSAFE, &AScale³D::on_set_scale3);
        w.slot(UNSAFE, &AScale³D::on_set_scaleX);
        w.slot(UNSAFE, &AScale³D::on_set_scaleY);
        w.slot(UNSAFE, &AScale³D::on_set_scaleZ);

        w.slot(UNSAFE, &AScale³D::on_add_scale3);
        w.slot(UNSAFE, &AScale³D::on_add_scaleX);
        w.slot(UNSAFE, &AScale³D::on_add_scaleY);
        w.slot(UNSAFE, &AScale³D::on_add_scaleZ);
        
        w.slot(UNSAFE, &AScale³D::on_multiply_scale);
        w.slot(UNSAFE, &AScale³D::on_multiply_scale3);
        w.slot(UNSAFE, &AScale³D::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale³D::on_multiply_scaleY);
        w.slot(UNSAFE, &AScale³D::on_multiply_scaleZ);
    }
}
