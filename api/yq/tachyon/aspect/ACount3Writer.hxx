////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ACount3.hpp>
#include <yq/tachyon/command/count/AddCount3Command.hpp>
#include <yq/tachyon/command/count/AddCountXCommand.hpp>
#include <yq/tachyon/command/count/AddCountYCommand.hpp>
#include <yq/tachyon/command/count/AddCountZCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCount3Command.hpp>
#include <yq/tachyon/command/count/MultiplyCountXCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountYCommand.hpp>
#include <yq/tachyon/command/count/MultiplyCountZCommand.hpp>
#include <yq/tachyon/command/count/SetCount3Command.hpp>
#include <yq/tachyon/command/count/SetCountXCommand.hpp>
#include <yq/tachyon/command/count/SetCountYCommand.hpp>
#include <yq/tachyon/command/count/SetCountZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ACount³::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<ICount³>();
        w.property(UNSAFE, "count", &ACount³::m_count).tag(kTag_Save);
        
        w.slot(UNSAFE, &ACount³::on_set_count3);
        w.slot(UNSAFE, &ACount³::on_set_countX);
        w.slot(UNSAFE, &ACount³::on_set_countY);
        w.slot(UNSAFE, &ACount³::on_set_countZ);

        w.slot(UNSAFE, &ACount³::on_add_count3);
        w.slot(UNSAFE, &ACount³::on_add_countX);
        w.slot(UNSAFE, &ACount³::on_add_countY);
        w.slot(UNSAFE, &ACount³::on_add_countZ);
        
        w.slot(UNSAFE, &ACount³::on_multiply_count);
        w.slot(UNSAFE, &ACount³::on_multiply_count3);
        w.slot(UNSAFE, &ACount³::on_multiply_countX);
        w.slot(UNSAFE, &ACount³::on_multiply_countY);
        w.slot(UNSAFE, &ACount³::on_multiply_countZ);
    }
}
