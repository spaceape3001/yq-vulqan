////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AScale3.hpp>
#include <yq/tachyon/command/scale/AddScale3Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale³::init_meta(TachyonMeta::Writer<C>&w)
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
