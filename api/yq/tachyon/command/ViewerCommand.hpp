////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerCommand : public Command {
        YQ_OBJECT_DECLARE(ViewerCommand, Command)
    public:
    
        static void init_meta();

    protected:
        ViewerCommand(const Header&);
        ViewerCommand(const ViewerCommand&, const Header&);
        virtual ~ViewerCommand();
    
    private:
        ViewerCommand(const ViewerCommand&) = delete;
        ViewerCommand(ViewerCommand&&) = delete;
        ViewerCommand& operator=(const ViewerCommand&) = delete;
        ViewerCommand& operator=(ViewerCommand&&) = delete;
    };
}
