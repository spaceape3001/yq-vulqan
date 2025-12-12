////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyCountCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountCommand, CountCommand)
    public:
        MultiplyCountCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountCommand(const MultiplyCountCommand&, const Header&);
        ~MultiplyCountCommand();
        MultiplyCountCommand(const Header&);

    private:
        unsigned  m_δ = 0.0;
        
        MultiplyCountCommand(const MultiplyCountCommand&) = delete;
        MultiplyCountCommand(MultiplyCountCommand&&) = delete;
        MultiplyCountCommand& operator=(const MultiplyCountCommand&) = delete;
        MultiplyCountCommand& operator=(MultiplyCountCommand&&) = delete;
    };
}
