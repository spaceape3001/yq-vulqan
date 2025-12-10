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
    class MultiplyMaxSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSize³Command, SizeCommand)
    public:
        MultiplyMaxSize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSize³Command(const MultiplyMaxSize³Command&, const Header&);
        MultiplyMaxSize³Command(const Header&);
        ~MultiplyMaxSize³Command();

    private:
        Vector3D  m_δ;
        
        MultiplyMaxSize³Command(const MultiplyMaxSize³Command&) = delete;
        MultiplyMaxSize³Command(MultiplyMaxSize³Command&&) = delete;
        MultiplyMaxSize³Command& operator=(const MultiplyMaxSize³Command&) = delete;
        MultiplyMaxSize³Command& operator=(MultiplyMaxSize³Command&&) = delete;
    };
}
