#include <random>

#include "catch.hpp"

#include "AppHdr.h"

#include "randbook.h"
#include "spl-book.h"

TEST_CASE( "When setting book spell list", "[single-file]" ) {

    item_def book;

    SECTION("spells will be padded with SPELL_NO_SPELL") {
        vector<spell_type> spells = {SPELL_MAGIC_DART, SPELL_CAUSE_FEAR};

        _set_book_spell_list(book, spells);

        const auto& book_spells = book.props[SPELL_LIST_KEY].get_vector();
        REQUIRE(book_spells.size() == RANDBOOK_SIZE);
        for (auto i = 2; i < RANDBOOK_SIZE; i++ )
            REQUIRE(book_spells[i].get_int() == SPELL_NO_SPELL);
    }

    // TODO: more test cases?
}
