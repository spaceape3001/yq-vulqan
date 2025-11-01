////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class RenderedCommand : public Command {
        YQ_OBJECT_DECLARE(RenderedCommand, Command)
    public:
    
        static void init_meta();

    protected:
        RenderedCommand(const Header&);
        RenderedCommand(const RenderedCommand&, const Header&);
        ~RenderedCommand();
        
    private:
        RenderedCommand(const RenderedCommand&) = delete;
        RenderedCommand(RenderedCommand&&) = delete;
        RenderedCommand& operator=(const RenderedCommand&) = delete;
        RenderedCommand& operator=(RenderedCommand&&) = delete;
    };
}
