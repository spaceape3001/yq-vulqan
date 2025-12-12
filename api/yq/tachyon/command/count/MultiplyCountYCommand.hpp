////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class MultiplyCountʸCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountʸCommand, CountCommand)
    public:
        MultiplyCountʸCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountʸCommand(const MultiplyCountʸCommand&, const Header&);
        MultiplyCountʸCommand(const Header&);
        ~MultiplyCountʸCommand();

    private:
        unsigned  m_δy = 0.0;
        
        MultiplyCountʸCommand(const MultiplyCountʸCommand&) = delete;
        MultiplyCountʸCommand(MultiplyCountʸCommand&&) = delete;
        MultiplyCountʸCommand& operator=(const MultiplyCountʸCommand&) = delete;
        MultiplyCountʸCommand& operator=(MultiplyCountʸCommand&&) = delete;
    };
}
