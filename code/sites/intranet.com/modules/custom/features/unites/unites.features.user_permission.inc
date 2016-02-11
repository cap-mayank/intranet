<?php
/**
 * @file
 * unites.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function unites_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create unites content'.
  $permissions['create unites content'] = array(
    'name' => 'create unites content',
    'roles' => array(
      'administrator' => 'administrator',
      'content approver' => 'content approver',
      'content author' => 'content author',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any unites content'.
  $permissions['delete any unites content'] = array(
    'name' => 'delete any unites content',
    'roles' => array(
      'administrator' => 'administrator',
      'content approver' => 'content approver',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own unites content'.
  $permissions['delete own unites content'] = array(
    'name' => 'delete own unites content',
    'roles' => array(
      'administrator' => 'administrator',
      'content approver' => 'content approver',
      'content author' => 'content author',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any unites content'.
  $permissions['edit any unites content'] = array(
    'name' => 'edit any unites content',
    'roles' => array(
      'administrator' => 'administrator',
      'content approver' => 'content approver',
      'content author' => 'content author',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own unites content'.
  $permissions['edit own unites content'] = array(
    'name' => 'edit own unites content',
    'roles' => array(
      'administrator' => 'administrator',
      'content approver' => 'content approver',
      'content author' => 'content author',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
