////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount1.hpp>
#include <yq/tachyon/command/count/AddCount1Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount1Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCount1Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount¹::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount¹>();
        w.property(UNSAFE, "count", &ACount¹::m_count).tag(kTag_Save);

        w.slot(UNSAFE, &ACount¹::on_set_count1);
        w.slot(UNSAFE, &ACount¹::on_set_countX);

        w.slot(UNSAFE, &ACount¹::on_add_count1);
        w.slot(UNSAFE, &ACount¹::on_add_countX);
        
        w.slot(UNSAFE, &ACount¹::on_multiply_count);
        w.slot(UNSAFE, &ACount¹::on_multiply_count1);
        w.slot(UNSAFE, &ACount¹::on_multiply_countX);
    }
}
