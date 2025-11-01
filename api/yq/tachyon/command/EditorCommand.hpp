////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class Editor;

    class EditorCommand : public Command {
        YQ_OBJECT_DECLARE(EditorCommand, Command)
    public:
    
        static void init_meta();

    protected:
        EditorCommand(const Header&);
        EditorCommand(const EditorCommand&, const Header&);
        virtual ~EditorCommand();
    
    private:
        EditorCommand(const EditorCommand&) = delete;
        EditorCommand(EditorCommand&&) = delete;
        EditorCommand& operator=(const EditorCommand&) = delete;
        EditorCommand& operator=(EditorCommand&&) = delete;
    };
}
