////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyCountUCommand : public CountCommand {
        YQ_OBJECT_DECLARE(MultiplyCountUCommand, CountCommand)
    public:
        MultiplyCountUCommand(const Header&, unsigned);
        
        static void init_meta();
        
        unsigned  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyCountUCommand(const MultiplyCountUCommand&, const Header&);
        ~MultiplyCountUCommand();
        MultiplyCountUCommand(const Header&);

    private:
        unsigned  m_δ = 0.0;
        
        MultiplyCountUCommand(const MultiplyCountUCommand&) = delete;
        MultiplyCountUCommand(MultiplyCountUCommand&&) = delete;
        MultiplyCountUCommand& operator=(const MultiplyCountUCommand&) = delete;
        MultiplyCountUCommand& operator=(MultiplyCountUCommand&&) = delete;
    };
}
