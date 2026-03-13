////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScale2.hpp>
#include <yq/tachyon/command/scale/AddScale2DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale2DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale2DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale²::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScale²>();
        w.property(UNSAFE, "scale", &AScale²::m_scale).tag(kTag_Save);

        w.slot(UNSAFE, &AScale²::on_set_scale2);
        w.slot(UNSAFE, &AScale²::on_set_scaleX);
        w.slot(UNSAFE, &AScale²::on_set_scaleY);

        w.slot(UNSAFE, &AScale²::on_add_scale2);
        w.slot(UNSAFE, &AScale²::on_add_scaleX);
        w.slot(UNSAFE, &AScale²::on_add_scaleY);
        
        w.slot(UNSAFE, &AScale²::on_multiply_scale);
        w.slot(UNSAFE, &AScale²::on_multiply_scale2);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale²::on_multiply_scaleY);
    }
}
