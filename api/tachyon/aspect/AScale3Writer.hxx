////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AScale3.hpp>
#include <tachyon/command/scale/AddScale3Command.hpp>
#include <tachyon/command/scale/AddScaleXCommand.hpp>
#include <tachyon/command/scale/AddScaleYCommand.hpp>
#include <tachyon/command/scale/AddScaleZCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <tachyon/command/scale/MultiplyScale3Command.hpp>
#include <tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleZCommand.hpp>
#include <tachyon/command/scale/SetScale3Command.hpp>
#include <tachyon/command/scale/SetScaleXCommand.hpp>
#include <tachyon/command/scale/SetScaleYCommand.hpp>
#include <tachyon/command/scale/SetScaleZCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale³::init_info(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IScale³>();
        w.property(UNSAFE, "scale", &AScale³::m_scale).tag(kTag_Save);
        
        w.slot(UNSAFE, &AScale³::on_set_scale3);
        w.slot(UNSAFE, &AScale³::on_set_scaleX);
        w.slot(UNSAFE, &AScale³::on_set_scaleY);
        w.slot(UNSAFE, &AScale³::on_set_scaleZ);

        w.slot(UNSAFE, &AScale³::on_add_scale3);
        w.slot(UNSAFE, &AScale³::on_add_scaleX);
        w.slot(UNSAFE, &AScale³::on_add_scaleY);
        w.slot(UNSAFE, &AScale³::on_add_scaleZ);
        
        w.slot(UNSAFE, &AScale³::on_multiply_scale);
        w.slot(UNSAFE, &AScale³::on_multiply_scale3);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleX);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleY);
        w.slot(UNSAFE, &AScale³::on_multiply_scaleZ);
    }
}
