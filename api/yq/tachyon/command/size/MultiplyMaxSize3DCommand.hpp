////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMaxSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize³DCommand, SizeCommand)
    public:
        MultiplyMaxSize³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize³DCommand(const MultiplyMaxSize³DCommand&, const Header&);
        MultiplyMaxSize³DCommand(const Header&);
        ~MultiplyMaxSize³DCommand();

    private:
        Vector3D  m_δ;
        
        MultiplyMaxSize³DCommand(const MultiplyMaxSize³DCommand&) = delete;
        MultiplyMaxSize³DCommand(MultiplyMaxSize³DCommand&&) = delete;
        MultiplyMaxSize³DCommand& operator=(const MultiplyMaxSize³DCommand&) = delete;
        MultiplyMaxSize³DCommand& operator=(MultiplyMaxSize³DCommand&&) = delete;
    };
}
