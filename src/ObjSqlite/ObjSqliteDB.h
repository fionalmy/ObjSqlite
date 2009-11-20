// Copyright 2009 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use this file except in compliance with the License. You may obtain
// a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#import <sqlite3.h>

#import "ObjSqliteStatement.h"


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
@interface ObjSqliteDB : NSObject {
@private
  sqlite3*  _db;

  NSString* _path;

  const char*         _createSQL;
  ObjSqliteStatement* _createStatement;
}

@property (nonatomic, readonly) sqlite3*  sqliteDB;

@property (nonatomic, readonly) int       lastErrorCode;
@property (nonatomic, readonly) NSString* lastErrorMessage;

/**
 * SQL that will be executed the first time the db is created.
 * You'd generally put your CREATE statement in here.
 */
@property (nonatomic, assign) const char* createSQL;


///////////////////////////////////////////////////////////////////////////////////////////////////
- (id) initWithPath:(NSString*)path;

- (void) close;

@end
