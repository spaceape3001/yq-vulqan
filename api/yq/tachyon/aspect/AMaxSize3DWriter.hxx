////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AMaxSize3D.hpp>
#include <yq/tachyon/command/size/AddMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/AddMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/MultiplyMaxSizeZDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSize3DCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeXDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeYDCommand.hpp>
#include <yq/tachyon/command/size/SetMaxSizeZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMaxSize³D::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMinSize³D>();
        w.property(UNSAFE, "max_size", &AMaxSize³D::m_max_size).tag(kTag_Save);

        w.slot(UNSAFE, &AMaxSize³D::on_set_max_size3);
        w.slot(UNSAFE, &AMaxSize³D::on_set_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³D::on_set_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³D::on_set_max_sizeZ);

        w.slot(UNSAFE, &AMaxSize³D::on_add_max_size3);
        w.slot(UNSAFE, &AMaxSize³D::on_add_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³D::on_add_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³D::on_add_max_sizeZ);
        
        w.slot(UNSAFE, &AMaxSize³D::on_multiply_max_size);
        w.slot(UNSAFE, &AMaxSize³D::on_multiply_max_size3);
        w.slot(UNSAFE, &AMaxSize³D::on_multiply_max_sizeX);
        w.slot(UNSAFE, &AMaxSize³D::on_multiply_max_sizeY);
        w.slot(UNSAFE, &AMaxSize³D::on_multiply_max_sizeZ);
    }
}
