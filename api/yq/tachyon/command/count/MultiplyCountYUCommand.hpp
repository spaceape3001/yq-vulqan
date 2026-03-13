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
    class MultiplyCountʸUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountʸUCommand, CountCommand)
    public:
        MultiplyCountʸUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δy() const { return m_δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountʸUCommand(const MultiplyCountʸUCommand&, const Header&);
        MultiplyCountʸUCommand(const Header&);
        ~MultiplyCountʸUCommand();

    private:
        unsigned  m_δy = 0.0;
        
        MultiplyCountʸUCommand(const MultiplyCountʸUCommand&) = delete;
        MultiplyCountʸUCommand(MultiplyCountʸUCommand&&) = delete;
        MultiplyCountʸUCommand& operator=(const MultiplyCountʸUCommand&) = delete;
        MultiplyCountʸUCommand& operator=(MultiplyCountʸUCommand&&) = delete;
    };
}
