////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount2.hpp>
#include <yq/tachyon/command/count/AddCount2Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount2Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCount2Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount²::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount²>();
        w.property(UNSAFE, "count", &ACount²::m_count).tag(kTag_Save);

        w.slot(UNSAFE, &ACount²::on_set_count2);
        w.slot(UNSAFE, &ACount²::on_set_countX);
        w.slot(UNSAFE, &ACount²::on_set_countY);

        w.slot(UNSAFE, &ACount²::on_add_count2);
        w.slot(UNSAFE, &ACount²::on_add_countX);
        w.slot(UNSAFE, &ACount²::on_add_countY);
        
        w.slot(UNSAFE, &ACount²::on_multiply_count);
        w.slot(UNSAFE, &ACount²::on_multiply_count2);
        w.slot(UNSAFE, &ACount²::on_multiply_countX);
        w.slot(UNSAFE, &ACount²::on_multiply_countY);
    }
}
