////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AScale1.hpp>
#include <tachyon/command/scale/AddScale1Command.hpp>
#include <tachyon/command/scale/AddScaleXCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <tachyon/command/scale/MultiplyScale1Command.hpp>
#include <tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <tachyon/command/scale/SetScale1Command.hpp>
#include <tachyon/command/scale/SetScaleXCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

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
