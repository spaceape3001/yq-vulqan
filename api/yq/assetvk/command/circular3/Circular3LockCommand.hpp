////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/command/Circular3Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class Circular³LockCommand : public Circular³Command {
        YQ_OBJECT_DECLARE(Circular³LockCommand, Circular³Command)
    public:
    
        static void init_meta();
        Circular³LockCommand(const Header&, bool);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
        bool    lock() const { return m_lock; }
        
    protected:
        Circular³LockCommand(const Circular³LockCommand&, const Header&);
        ~Circular³LockCommand();
        
    private:
        bool    m_lock;
    
        Circular³LockCommand(const Circular³LockCommand&) = delete;
        Circular³LockCommand(Circular³LockCommand&&) = delete;
        Circular³LockCommand& operator=(const Circular³LockCommand&) = delete;
        Circular³LockCommand& operator=(Circular³LockCommand&&) = delete;
    };
}
