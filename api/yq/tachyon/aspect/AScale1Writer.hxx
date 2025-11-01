////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScale1.hpp>
#include <yq/tachyon/command/scale/AddScale1Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale1Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScale1Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale¹::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScale¹>();
        w.property(UNSAFE, "scale", &AScale¹::m_scale).tag(kTag_Save);

        w.slot(UNSAFE, &AScale¹::on_set_scale1);
        w.slot(UNSAFE, &AScale¹::on_set_scaleX);

        w.slot(UNSAFE, &AScale¹::on_add_scale1);
        w.slot(UNSAFE, &AScale¹::on_add_scaleX);
        
        w.slot(UNSAFE, &AScale¹::on_multiply_scale);
        w.slot(UNSAFE, &AScale¹::on_multiply_scale1);
        w.slot(UNSAFE, &AScale¹::on_multiply_scaleX);
    }
}
