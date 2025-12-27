////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SpatialCommand.hpp>

namespace yq::tachyon {
    class FileCommand : public SpatialCommand {
        YQ_OBJECT_DECLARE(FileCommand, SpatialCommand)
    public:
        FileCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        FileCommand(const FileCommand&, const Header&);
        virtual ~FileCommand();
        
    private:

        FileCommand(const FileCommand&) = delete;
        FileCommand(FileCommand&&) = delete;
        FileCommand& operator=(const FileCommand&) = delete;
        FileCommand& operator=(FileCommand&&) = delete;
    };
}
