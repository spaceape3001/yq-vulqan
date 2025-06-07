////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AScale2.hpp>
#include <tachyon/command/scale/AddScale2Command.hpp>
#include <tachyon/command/scale/AddScaleXCommand.hpp>
#include <tachyon/command/scale/AddScaleYCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <tachyon/command/scale/MultiplyScale2Command.hpp>
#include <tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <tachyon/command/scale/SetScale2Command.hpp>
#include <tachyon/command/scale/SetScaleXCommand.hpp>
#include <tachyon/command/scale/SetScaleYCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AScale²::init_info(TachyonInfo::Writer<C>&w)
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
