/**
 * Daniel Sebastian Iliescu, http://dansil.net
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * 
 * Doubly Linked List Unit Tests.
 */

#include "lists/doubly_linked_list.hpp"

#include "utilities/generator.hpp"

#include <catch.hpp>

#include <array>

namespace
{
	const std::string UNIT_NAME = "doubly_linked_list_";

	using value_type = std::int32_t;
	constexpr auto ITERATIONS = 1000U;
}

namespace dsa
{
	TEST_CASE( ( UNIT_NAME + "default_constructor" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "copy_constructor_push_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );

		auto list_copy( list );

		REQUIRE( list == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "copy_constructor_push_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto list_copy( list );

		REQUIRE( list == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "move_constructor_push_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );

		const auto list_copy( list );
		const auto list_move( std::move( list ) );

		REQUIRE( list.empty() );
		REQUIRE( list_move == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "move_constructor_push_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto list_copy( list );
		const auto list_move( std::move( list ) );

		REQUIRE( list.empty() );
		REQUIRE( list_move == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "copy_assignment_push_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );

		const auto list_copy = list;

		REQUIRE( list == list );
	}

	TEST_CASE( ( UNIT_NAME + "copy_assignment_push_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto list_copy = list;

		REQUIRE( list == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "move_assignment_push_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );

		const auto list_copy = list;
		const auto list_move = std::move( list );

		REQUIRE( list.empty() );
		REQUIRE( list_move == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "move_assignment_push_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto list_copy = list;
		const auto list_move = std::move( list );

		REQUIRE( list.empty() );
		REQUIRE( list_move == list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "equality_operator_push_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );

		auto list_copy = list;

		REQUIRE( list == list_copy );

		list.clear();
		list_copy.clear();

		generator.fill_buffer_n( std::front_inserter( list ), ITERATIONS );
		generator.fill_buffer_n( std::front_inserter( list_copy ), ITERATIONS );

		REQUIRE( list != list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "equality_operator_push_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		auto list_copy = list;

		REQUIRE( list == list_copy );

		list.clear();
		list_copy.clear();

		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );
		generator.fill_buffer_n( std::back_inserter( list_copy ), ITERATIONS );

		REQUIRE( list != list_copy );
	}

	TEST_CASE( ( UNIT_NAME + "empty_pop_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		list.pop_front();

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "empty_pop_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		list.pop_back();

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "clear" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		list.clear();

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "peek_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto expected_value = list.front();

		REQUIRE( expected_value == list.pop_front() );
	}

	TEST_CASE( ( UNIT_NAME + "peek_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		generator< value_type > generator;
		generator.fill_buffer_n( std::back_inserter( list ), ITERATIONS );

		const auto expected_value = list.back();

		REQUIRE( expected_value == list.pop_back() );
	}

	TEST_CASE( ( UNIT_NAME + "empty_peek_front" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		REQUIRE( value_type() == list.front() );
	}

	TEST_CASE( ( UNIT_NAME + "empty_peek_back" ).c_str() )
	{
		doubly_linked_list< value_type > list;

		REQUIRE( value_type() == list.back() );
	}

	TEST_CASE( ( UNIT_NAME + "push_front_pop_back" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE( ITERATIONS == list.size() );

		for ( auto&& value : values )
		{
			REQUIRE( value == list.pop_back() );
		}

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "push_front_pop_front" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE( ITERATIONS == list.size() );

		for ( auto it = std::rbegin( values ); it != std::rend( values ); ++it )
		{
			REQUIRE( *it == list.pop_front() );
		}

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "push_back_pop_back" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE( ITERATIONS == list.size() );

		for ( auto it = std::rbegin( values ); it != std::rend( values ); ++it )
		{
			REQUIRE( *it == list.pop_back() );
		}

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "push_back_pop_front" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE( ITERATIONS == list.size() );

		for ( auto&& value : values )
		{
			REQUIRE( value == list.pop_front() );
		}

		REQUIRE( list.empty() );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_front_begin_end" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE(
			std::equal(
				std::crbegin( values ),
				std::crend( values ),
				std::begin( list ),
				std::end( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_back_begin_end" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE(
			std::equal(
				std::cbegin( values ),
				std::cend( values ),
				std::begin( list ),
				std::end( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_front_rbegin_rend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE(
			std::equal(
				std::cbegin( values ),
				std::cend( values ),
				std::rbegin( list ),
				std::rend( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_back_rbegin_rend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE(
			std::equal(
				std::crbegin( values ),
				std::crend( values ),
				std::rbegin( list ),
				std::rend( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_front_cbegin_cend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE(
			std::equal(
				std::crbegin( values ),
				std::crend( values ),
				std::cbegin( list ),
				std::cend( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_back_cbegin_cend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE(
			std::equal(
				std::cbegin( values ),
				std::cend( values ),
				std::cbegin( list ),
				std::cend( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_front_crbegin_crend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::front_inserter( list ) );

		REQUIRE(
			std::equal(
				std::cbegin( values ),
				std::cend( values ),
				std::crbegin( list ),
				std::crend( list ) ) );
	}

	TEST_CASE( ( UNIT_NAME + "iterator_push_back_crbegin_crend" ).c_str() )
	{
		std::array< value_type, ITERATIONS > values;

		generator< value_type > generator;
		generator.fill_buffer(
			std::begin( values ),
			std::end( values ) );

		doubly_linked_list< value_type > list;
		std::copy(
			std::cbegin( values ),
			std::cend( values ),
			std::back_inserter( list ) );

		REQUIRE(
			std::equal(
				std::crbegin( values ),
				std::crend( values ),
				std::crbegin( list ),
				std::crend( list ) ) );
	}
}
