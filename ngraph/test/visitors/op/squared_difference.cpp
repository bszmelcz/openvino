// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "gtest/gtest.h"

#include "ngraph/ngraph.hpp"
#include "ngraph/op/util/attr_types.hpp"
#include "ngraph/opsets/opset1.hpp"
#include "ngraph/opsets/opset3.hpp"
#include "ngraph/opsets/opset4.hpp"
#include "ngraph/opsets/opset5.hpp"

#include "util/visitor.hpp"

using namespace std;
using namespace ngraph;
using ngraph::test::NodeBuilder;
using ngraph::test::ValueMap;

TEST(attributes, squared_difference_op)
{
    NodeBuilder::get_ops().register_factory<opset1::SquaredDifference>();
    auto x1 = make_shared<op::Parameter>(element::i32, Shape{200});
    auto x2 = make_shared<op::Parameter>(element::i32, Shape{200});
    auto auto_broadcast = op::AutoBroadcastType::NUMPY;
    auto squared_difference = make_shared<opset1::SquaredDifference>(x1, x2, auto_broadcast);
    NodeBuilder builder(squared_difference);
    auto g_squared_difference = as_type_ptr<opset1::SquaredDifference>(builder.create());

    EXPECT_EQ(g_squared_difference->get_autob(), squared_difference->get_autob());
}
