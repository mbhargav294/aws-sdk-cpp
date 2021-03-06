﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ecs/model/ResourceRequirement.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace ECS
{
namespace Model
{

ResourceRequirement::ResourceRequirement() : 
    m_valueHasBeenSet(false),
    m_type(ResourceType::NOT_SET),
    m_typeHasBeenSet(false)
{
}

ResourceRequirement::ResourceRequirement(JsonView jsonValue) : 
    m_valueHasBeenSet(false),
    m_type(ResourceType::NOT_SET),
    m_typeHasBeenSet(false)
{
  *this = jsonValue;
}

ResourceRequirement& ResourceRequirement::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("value"))
  {
    m_value = jsonValue.GetString("value");

    m_valueHasBeenSet = true;
  }

  if(jsonValue.ValueExists("type"))
  {
    m_type = ResourceTypeMapper::GetResourceTypeForName(jsonValue.GetString("type"));

    m_typeHasBeenSet = true;
  }

  return *this;
}

JsonValue ResourceRequirement::Jsonize() const
{
  JsonValue payload;

  if(m_valueHasBeenSet)
  {
   payload.WithString("value", m_value);

  }

  if(m_typeHasBeenSet)
  {
   payload.WithString("type", ResourceTypeMapper::GetNameForResourceType(m_type));
  }

  return payload;
}

} // namespace Model
} // namespace ECS
} // namespace Aws
