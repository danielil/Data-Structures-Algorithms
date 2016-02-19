/**
 * Daniel Sebastian Iliescu
 *
 * An implementation of insertion sort.
 */

#pragma once

namespace dsa
{
    template < typename T >
    void insertionsort( T* data, const std::size_t size )
    {
        if ( ( data != nullptr ) &&
             ( size >= 0 ) )
        {
            for ( std::size_t idx = 1; idx < size; ++idx )
            {
                T current = data[idx];

                std::size_t insertPos = idx;

                while ( ( insertPos != 0 ) &&
                        ( current < data[insertPos - 1] ) )
                {
                    data[insertPos] = data[insertPos - 1];
                    --insertPos;
                }

                data[insertPos] = current;
            }
        }
    }
}