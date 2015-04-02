<?php

/**
 * @file
 * Plugin to provide an relationship handler 'edit form' for Profile2.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Profile2 edit form'),
  'keyword' => 'profile2_edit_form',
  'description' => t('Adds profile2 edit form from a profile2 context.'),
  'required context' => new ctools_context_required(t('Profile2'), 'entity:profile2'),
  'context' => 'profile2_panels_edit_form_from_profile2_context',
);

/**
 * Return a new context based on an existing context.
 */
function profile2_panels_edit_form_from_profile2_context($context, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('profile2_edit_form', NULL);
  }

  if (isset($context->data->pid)) {
    return ctools_context_create('profile2_edit_form', $context->data);
  }
}
